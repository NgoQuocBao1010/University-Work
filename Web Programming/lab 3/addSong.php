<?php
    // Database connection 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    // Get post data
    $error = false;
    $maBaiViet = $tieuDe = $maTacGia = $ngayViet = $tenBaiHat = $maTheLoai = $tomTat = "";
    $maBaiVietErr = $tieuDeErr = $maTacGiaErr = $ngayVietErr = $tenBaiHatErr = $maTheLoaiErr = $tomTatErr = "";

    if (isset($_POST['submit'])) {
        if (empty($_POST['maBaiViet'])) {
            $maBaiVietErr = "Đây là trường bắt buộc (không nên thay đổi giá trị mặc định)!";
            $error = true;
            $maBaiViet =  generateID($conn);
        }
        elseif (!numberOnlyValidation($_POST['maBaiViet'])) {
            $maBaiVietErr = "Mã chỉ có nhận đầu vào là số!";
            $error = true;
            $maBaiViet = $_POST['maBaiViet'];
        }
        else {
            $maBaiViet = $_POST['maBaiViet'];
        }      
        

        if (empty($_POST['tieuDe'])) {
            $tieuDeErr = "Đây là trường bắt buộc!";
            $error = true;
        }
        $tieuDe = $_POST['tieuDe'];


        if (empty($_POST['maTacGia'])) {
            $maTacGiaErr = "Đây là trường bắt buộc!";
            $error = true;
        }
        elseif (!numberOnlyValidation($_POST['maTacGia'])) {
            $maTacGiaErr = "Mã chỉ có nhận đầu vào là số!";
            $error = true;
        } 
        $maTacGia = $_POST['maTacGia'];



        if (empty($_POST['ngayViet'])) {
            $ngayVietErr = "Đây là trường bắt buộc!";
            $ngayViet = date("Y-m-d");
            $error = true;
        }
        elseif (!dateValidation($_POST['ngayViet'])) {
            $ngayVietErr = "Ngày nên được nhập với dạng yyyy-mm-dd";
            $error = true;
            $ngayViet = $_POST['ngayViet'];
        }
        else {
            $ngayViet = $_POST['ngayViet'];
        }
        

        if (empty($_POST['tenBaiHat'])) {
            if (!empty($_POST['tieuDe'])) {
                $tenBaiHat = $tieuDe;
                $error = true;
            }
        }
        $tenBaiHat = $_POST['tenBaiHat'];



        if (empty($_POST['maTheLoai'])) {
            $maTheLoaiErr = "Đây là trường bắt buộc!";
            $error = true;
        }
        elseif (!numberOnlyValidation($_POST['maTheLoai'])) {
            $maTheLoaiErr = "Mã chỉ có nhận đầu vào là số!";
            $error = true;
        } 
        $maTheLoai = $_POST['maTheLoai'];


        if (empty($_POST['tomTat'])) {
            $tomTatErr = "Đây là trường bắt buộc!";
            $error = true;
        }
        $tomTat = $_POST['tomTat'];

        if ($error) {
        }
        else {
            $insertInto = "INSERT INTO Reviews (maBaiViet, tieuDe, tenBaiHat, maTheLoai, tomTat, baiViet,       maTacGia, ngayViet)
                            VALUES ('$maBaiViet', '$tieuDe', '$tenBaiHat', '$maTheLoai', '$tomTat', '$tomTat', '$maTacGia', '$ngayViet')";
            if (mysqli_query($conn, $insertInto)) {
                header('Location: deleteSong.php');
            } 
            else 
            {
                echo "Error: " . $insertInto . "<br>" . mysqli_error($conn);
            }
        }
    }

    else {
        // Generate new Id
        $maBaiViet = $tieuDe = $maTacGia = $ngayViet = $tenBaiHat = $maTheLoai = $tomTat = "";
        $maBaiViet = generateID($conn);
        $ngayViet = date("Y-m-d");
    }

    // Get reviews from database
    $getReviews = "SELECT maBaiViet, tieuDe, tenBaiHat, tomTat, ngayViet, tenTacGia, tenTheLoai
            FROM Reviews 
            LEFT JOIN Reviewers on Reviews.maTacGia = Reviewers.maTacGia
            LEFT JOIN Genres on Reviews.maTheLoai = Genres.maTheLoai";
    
    $result = mysqli_query($conn, $getReviews);
    $reviews = mysqli_fetch_all($result, MYSQLI_ASSOC);

    // Get reviewers from database
    $getReviewers = "SELECT * from Reviewers";
    $result = mysqli_query($conn, $getReviewers);
    $reviewers = mysqli_fetch_all($result, MYSQLI_ASSOC);

    // Get genres from database
    $getGenres = "SELECT * from Genres";
    $result = mysqli_query($conn, $getGenres);
    $genres = mysqli_fetch_all($result, MYSQLI_ASSOC);

    function generateID($connection) {
        $getLastReviewID = "SELECT MAX(maBaiViet) as maGanNhat FROM Reviews";
        $result = mysqli_query($connection, $getLastReviewID);
        $lastID = mysqli_fetch_array($result, MYSQLI_ASSOC)['maGanNhat'];
        $newID = $lastID + 1;

        return $newID;
    }

    function numberOnlyValidation($str) {
        $pattern = "/^[0-9]*$/";
        return preg_match($pattern, $str);
    }

    function dateValidation($str) {
        $pattern = "/^\d{4}\-(0?[1-9]|1[012])\-(0?[1-9]|[12][0-9]|3[01])$/";
        return preg_match($pattern, $str);
    }
    
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Them Bai Viet</title>
    <link rel="stylesheet" href="style.css">
</head>
<body>
    <div class="container">
        <h1>Thêm Bài Viết</h1>
        <hr>
        <div class="form">
            <form action="addSong.php" method="post">
                <div class="field">
                    <div class="label">Mã bài viết</div>
                    <div class="input">
                        <input type="text" name="maBaiViet" value="<?php echo $maBaiViet; ?>" style="width: 30%;">
                        <div class="error">
                            <?php echo $maBaiVietErr ?>
                        </div>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Tiêu đề</div>
                    <div class="input">
                        <input type="text" name="tieuDe" value="<?php echo $tieuDe; ?>">
                        <p class="error"><?php echo $tieuDeErr?></p>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Tác giả</div>
                    <div class="input">
                        <select style="width: 40%; height: 30px;" name="maTacGia" id="">
                            <?php foreach ($reviewers as $reviewer): ?>
                                <option value='<?php echo $reviewer['maTacGia'] ?>'><?php echo $reviewer['tenTacGia']; ?></option>
                            <?php endforeach; ?>
                        </select>
                        <p class="error"><?php echo $maTacGiaErr?></p>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Ngày Viết</div>
                    <div class="input">
                        <input type="date" name="ngayViet" value="<?php echo $ngayViet; ?>" id="ngayViet">
                        <p class="error"><?php echo $ngayVietErr?></p>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Bài Hát</div>
                    <div class="input">
                        <input type="text" name="tenBaiHat" value="<?php echo $tenBaiHat ?>">
                        <p class="error"><?php echo $tenBaiHatErr?></p>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Thể Loại</div>
                    <div class="input">
                        <select style="width: 40%; height: 30px;" name="maTheLoai">
                            <?php foreach ($genres as $genre): ?>
                                <option value='<?php echo $genre['maTheLoai'] ?>'><?php echo $genre['tenTheLoai']; ?></option>
                            <?php endforeach; ?>
                        </select>
                        <p class="error"><?php echo $maTheLoaiErr?></p>
                    </div>
                </div>
                <div class="field">
                    <div class="label">Tóm tắt</div>
                    <div class="input">
                        <textarea name="tomTat" rows="5" cols="40"><?php echo $tomTat ?></textarea>
                        <p class="error"><?php echo $tomTatErr?></p>
                    </div>
                </div>

                <div class="field">
                    <div class="label"></div>
                    <div class="input">
                        <input id="submitBtn" type="submit" name="submit" value="Thêm Bài Viết">
                    </div>
                </div>
            </form>
        </div>

        <br>
        <hr>

        <div class="musicList">
        <?php for ($i=0; $i<count($reviews); $i+=1): ?>
            <p>
                <b><?php echo ($i + 1) . ". " . $reviews[$i]['tenBaiHat'] . ", ";  ?></b>
                <?php echo $reviews[$i]['tenTacGia']  . ", ";  ?>
                <?php echo $reviews[$i]['ngayViet']  . ".";  ?>
            </p>
        <?php endfor; ?>
        </div>
    </div>
</body>
</html>