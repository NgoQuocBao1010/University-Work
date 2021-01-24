create table PRO_Khoa (
    makhoa char(8) primary key,
    tenkhoa nchar(25),
    socbgd int check (socbgd > 0)
);


create table PRO_MonHoc (
    mamh char(8) primary key,
    tenmh nchar(25),
    sotiet int check (sotiet > 0)
);

create table PRO_SinhVien (
    masv char(8) primary key,
    hoten nchar(25),
    ngaysinh date,
    makhoa char(8),
    noisinh nchar(40),
    FOREIGN KEY (makhoa) REFERENCES PRO_Khoa(makhoa)
);

create table PRO_KetQua (
    masv char(8),
    mamh char(8),
    diemthi number(3, 2),
    FOREIGN KEY (masv) REFERENCES PRO_SinhVien(masv),
    FOREIGN KEY (mamh) REFERENCES PRO_MonHoc(mamh),
    primary key (masv, mamh)
);



-- Insert Data to Tables
insert into PRO_Khoa values ('k01', 'Khoa Công Ngh? Thông Tin', 40);
insert into PRO_Khoa values ('k02', 'Khoa Chính Tr?', 30);
insert into PRO_Khoa values ('k03', 'Khoa Môi Tr??ng', 25);

insert into PRO_MonHoc values ('m01', 'Toán R?i R?c', 20);
insert into PRO_MonHoc values ('m02', 'T? T??ng HCM', 15);
insert into PRO_MonHoc values ('m03', 'Tin H?c C?n B?n', 15);

insert into PRO_SinhVien values ('b01', 'ZyWoo', TO_DATE('10/10/2000', 'DD/MM/YYYY'), 'k01', 'France');
insert into PRO_SinhVien values ('b02', 'Twitszz', TO_DATE('08/05/1999', 'DD/MM/YYYY'), 'k02', 'Canada');
insert into PRO_SinhVien values ('b03', 'huNter', TO_DATE('15/12/1990', 'DD/MM/YYYY'), 'k03', 'Ukraine');
insert into PRO_SinhVien values ('b04', 'EliGe', TO_DATE('10/08/1992', 'DD/MM/YYYY'), 'k02', 'USA');
insert into PRO_SinhVien values ('b05', 'Stewie', TO_DATE('02/10/1992', 'DD/MM/YYYY'), 'k01', 'USA');
insert into PRO_SinhVien values ('b06', 'Sad', TO_DATE('20/02/2000', 'DD/MM/YYYY'), 'k01', 'VietNam');

insert into PRO_KetQua values ('b01', 'm01', '9.7');
insert into PRO_KetQua values ('b02', 'm01', '8.3');
insert into PRO_KetQua values ('b06', 'm01', '7.0');
insert into PRO_KetQua values ('b05', 'm01', '9.0');
insert into PRO_KetQua values ('b04', 'm02', '5.5');
insert into PRO_KetQua values ('b03', 'm02', '8.1');
insert into PRO_KetQua values ('b01', 'm02', '3.7');
insert into PRO_KetQua values ('b04', 'm03', '9');
insert into PRO_KetQua values ('b05', 'm03', '9.2');
insert into PRO_KetQua values ('b03', 'm03', '9.2');
insert into PRO_KetQua values ('b02', 'm03', '9.3');

select * from PRO_sinhvien;


-- Procedures
create or replace procedure add_sinhvien (masv char, hoten nchar, ngaysinh date, makhoa char, noisinh nchar)
is
begin
    insert into PRO_sinhvien(masv, hoten, ngaysinh, makhoa, noisinh) values(masv, hoten, ngaysinh, makhoa, noisinh);
end;
execute add_sinhvien('b07', 'shox', '10-OCT-00', 'k01', 'France');


create or replace procedure deleteSV (masv1 char)
is
begin
    delete from PRO_sinhvien
    where PRO_sinhvien.masv = masv1;
end;
execute deleteSV('b07');


-- Functions
create or replace function sinhVienDiemCaoNhat(tenmon nchar)
    return nchar
    is
        maxdiem number(4, 2);
        ten nchar(25);
    begin
        select max(diemthi) into maxdiem from PRO_KetQua
            inner join PRO_MonHoc on PRO_KetQua.mamh = PRO_MonHoc.mamh
            where PRO_MonHoc.tenmh=tenmon
        group by PRO_KetQua.mamh;
        
        select hoten into ten from PRO_SinhVien
            inner join PRO_KetQua on PRO_SinhVien.masv = PRO_KetQua.masv
            inner join PRO_MonHoc on PRO_KetQua.mamh = PRO_MonHoc.mamh
            where tenmh=tenmon and diemthi=maxdiem;
        return ten;
    end;
select sinhVienDiemCaoNhat('Toán R?i R?c') from dual;


create or replace function diemTBCaoNhatKhoa(khoa nchar)
    return nchar
    is
        maxdiemTB number(4, 2);
        ten nchar(25);
    begin
        select max(diemTB) into maxdiemtb from 
            (select avg(diemthi) as diemTB from PRO_KetQua
                inner join PRO_SinhVien on PRO_SinhVien.masv = PRO_KetQua.masv
                inner join PRO_Khoa on PRO_Khoa.makhoa = PRO_SinhVien.makhoa
                where tenkhoa=khoa
                group by PRO_KetQua.masv);
        
        select hoten into ten from PRO_SinhVien
            inner join PRO_KetQua on PRO_SinhVien.masv = PRO_KetQua.masv
            inner join PRO_Khoa on PRO_Khoa.makhoa = PRO_SinhVien.makhoa
            where tenkhoa=khoa
            group by hoten
            having avg(diemthi)=maxdiemTB;
        return ten;
    end;
select diemTBCaoNhatKhoa('Khoa Chính Tr?') from dual;


-- Triggers
create table PRO_SuaDiem(
    euser varchar2(30),
    ptime timestamp,
    masv char(8),
    mamh char(8),
    oldmark number(4,2),
    newmark number(4,2)
);

create or replace trigger triggerSuaDiem
after update on PRO_KetQua
for each row
begin
    insert into PRO_SuaDiem values(user, sysdate, :old.masv, :old.mamh, :old.diemthi, :new.diemthi);
end;

update PRO_KetQua set diemthi=3.5 where masv = 'b06' and mamh='m01';
select * from PRO_SuaDiem;


create table PRO_ThemDiem(
    auser varchar2(30),
    ptime timestamp,
    masv char(8),
    mamh char(8),
    tmark number(4,2)
);
        
create or replace trigger triggerThemDiem
after insert on PRO_KetQua
for each row
begin
    insert into PRO_ThemDiem values(user, sysdate, :new.masv, :new.mamh, :new.diemthi);
end;        
        
insert into PRO_KetQua values ('b04', 'm01', '9.3');
select * from PRO_ThemDiem;

















