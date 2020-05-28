package baiTH3;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Date2 {
	private int ngay;
    private int thang;
    private int nam;

    public int getNam() {
        return nam;
    }

    public void setNam(int nam) {
        this.nam = nam;
    }

    public int getThang() {
        return thang;
    }

    public void setThang(int thang) {
        this.thang = thang;
    }

    public int getNgay() {
        return ngay;
    }

    public void setNgay(int ngay) {
        this.ngay = ngay;
    }

    public Date2() {

    }

    public Date2(int ngay, int thang, int nam) {
        this.ngay = ngay;
        this.thang = thang;
        this.nam = nam;
    }

    public void hienThi() {
        System.out.println("Ngay " + getNgay() + " thang " + getThang() + " nam " + getNam());
    }

    public void nhap() {
        Scanner sc = new Scanner(System.in);
        boolean flag = true;

        do {
            try {
                System.out.print("Nhap ngay: ");
                setNgay(sc.nextInt());
                System.out.print("Nhap thang: ");
                setThang(sc.nextInt());
                System.out.print("Nhap nam: ");
                setNam(sc.nextInt());
                flag = true;
            } catch (InputMismatchException e) {
                System.out.println("Ngay khong hop le");
                sc.nextLine();
                flag = false;
            }
        } while (!flag);
    }

    public boolean namNhuan() {
        if (getNam() % 4 == 0) {
            if (getNam() % 100 == 0) {
                return getNam() % 400 == 0;
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    public boolean hopLe() {
        if (getThang() == 2) {
            if (namNhuan()) {
                return getNgay() > 0 && getNgay() <= 29;
            } else {
                return getNgay() > 0 && getNgay() <= 28;
            }
        } else if (getThang() == 1 || getThang() == 3 || getThang() == 5 || getThang() == 7 || getThang() == 8 || getThang() == 10 || getThang() == 12) {
            return getNgay() > 0 && getNgay() <= 31;
        } else {
            return getNgay() > 0 && getNgay() <= 30;
        }
    }

    public Date2 ngayHomSau() {
        Date2 D = new Date2();
        D.ngay = ngay;
        D.thang = thang;
        D.nam = nam;

        if (D.getThang() == 2) {
            if (D.namNhuan()) {
                if (D.getNgay() == 29) {
                    D.setNgay(1);
                    D.setThang(D.getThang() + 1);
                } else {
                    D.setNgay(D.getNgay() + 1);
                }
            } else {
                if (D.getNgay() == 28) {
                    D.setNgay(1);
                    D.setThang(D.getThang() + 1);
                } else {
                    D.setNgay(D.getNgay() + 1);
                }
            }
        } else if (D.getThang() == 1 || D.getThang() == 3 || D.getThang() == 5 || D.getThang() == 7 || D.getThang() == 8 || D.getThang() == 10) {
            if (D.getNgay() == 31) {
                D.setNgay(1);
                D.setThang(D.getThang() + 1);
            } else {
                D.setNgay(D.getNgay() + 1);
            }
        } else if (D.getThang() == 4 || D.getThang() == 6 || D.getThang() == 9 || D.getThang() == 11) {
            if (D.getNgay() == 30) {
                D.setNgay(1);
                D.setThang(D.getThang() + 1);
            } else {
                D.setNgay(D.getNgay() + 1);
            }
        } else if (D.getThang() == 12) {
            if (D.getNgay() == 31) {
                D.setNgay(1);
                D.setThang(1);
                D.setNam(D.getNam() + 1);
            } else {
                D.setNgay(D.getNgay() + 1);
            }
        }

        return D;
    }

    public Date2 congNgay(int n) {
        Date2 D = new Date2();
        D.setNgay(getNgay());
        D.setThang(getThang());
        D.setNam(getNam());

        for (int i = 0; i < n; i++) {
            D = D.ngayHomSau();
        }

        return D;
    }
    
    
    public Date2 addDays(int n) {
    	Date2 D = new Date2(ngay, thang, nam);
        
    	int soNgayTongCong = D.getNgay() + n;
    	D.setNgay(soNgayTongCong);
    	
    	do {
    		
    		if (D.getThang() == 2) {
    			if (D.namNhuan()) {
    				if (D.getNgay() > 29) {
    					soNgayTongCong -= 29;
    					D.setNgay(soNgayTongCong);
    					D.setThang(D.getThang() + 1);
    				}
    				else {
    					D.setNgay(D.getNgay());
    				}
    			}
    			else {
    				if (D.getNgay() > 28) {
    					soNgayTongCong -= 28;
    					D.setNgay(soNgayTongCong);
    					D.setThang(D.getThang() + 1);
    				}
    				else {
    					D.setNgay(D.getNgay());
    				}
    			}
    		}
    		else if (D.getThang() == 1 || D.getThang() == 3 || D.getThang() == 5 || D.getThang() == 7 || D.getThang() == 8 || D.getThang() == 10) {
    			if (D.getNgay() > 31) {
    				soNgayTongCong -= 31;
    				D.setNgay(soNgayTongCong);
    				D.setThang(D.getThang() + 1);
    			}
    			else {
    				D.setNgay(D.getNgay());
    			}
    		}
    		else if (D.getThang() == 4 || D.getThang() == 6 || D.getThang() == 9 || D.getThang() == 11) {
    			if (D.getNgay() > 30) {
    				soNgayTongCong -= 30;
    				D.setNgay(soNgayTongCong);
    				D.setThang(D.getThang() + 1);
    			}
    			else {
    				D.setNgay(D.getNgay());
    			}
    		}
    		else if (D.getThang() == 12) {
    			if (D.getNgay() > 31) {
    				soNgayTongCong -= 31;
    				D.setNgay(soNgayTongCong);
    				D.setThang(1);
    				D.setNam(D.getNam() + 1);
    			}
    			else {
    				D.setNgay(D.getNgay());
    			}
    		}
    	}
        while (!D.hopLe());
        
        return D;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Date2 a = new Date2(25, 3, 2018);
		Date2 b = a.addDays(1000);
		//System.out.println(a.hopLe());
		b.hienThi();
	}

}
