<?php 
    // Database connection 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    // Get reviewers from database
    $getReviews = "SELECT * from Reviews";
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


    $maBaiViet = $tieuDe = $maTacGia = $ngayViet = $tenBaiHat = $maTheLoai = $tomTat = "";
    if (isset($_POST['submit'])) {
        $maBaiViet = $_POST['maBaiViet'];
        $tieuDe = $_POST['tieuDe'];
        $maTacGia = $_POST['maTacGia'];
        $ngayViet = $_POST['ngayViet'];
        $tenBaiHat = $_POST['tenBaiHat'];
        $maTheLoai = $_POST['maTheLoai'];
        $tomTat = $_POST['tomTat'];


        $updateQuery = "UPDATE Reviews SET 
                        tieuDe='$tieuDe', tenBaiHat='$tenBaiHat', 
                        tomTat='$tomTat', ngayViet='$ngayViet', 
                        maTacGia=$maTacGia, maTheLoai=$maTheLoai
                        WHERE maBaiViet=$maBaiViet ";

        if (mysqli_query($conn, $updateQuery)) {
            header('Location: editSong.php');
        }
        else  {
            echo "Error: " . mysqli_error($conn);
        }
    }

    mysqli_close($conn);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="editSong.css">
    <title>Sua Bai Hat</title>

    <script>
        function getReview(selectedName) {
            if (selectedName == "") {
                return;
            } else {
                var xmlhttp = new XMLHttpRequest();
                xmlhttp.onreadystatechange = function() {
                    if (this.readyState == 4 && this.status == 200) {
                        var review = JSON.parse(this.responseText)[0];
                        
                        for (field in review) {
                            console.log(field + ' ' + review[field]);
                            document.getElementsByName(field)[0].value = review[field];
                        }
                    }
                };
                xmlhttp.open("GET","getReview.php?q=" + selectedName, true);
                xmlhttp.send();
            }
        }
    </script>
</head>
<body>
    <div class="container">
        <h1>Sửa thông tin bài viết</h1>
        <hr>

        <div class="field">
            <div class="label">
                <label for="">Chọn bài viết</label>
            </div>
            <div class="input">
                <select name="" id="" onchange="getReview(this.value)">
                    <?php foreach ($reviews as $review): ?>
                        <option value='<?php echo $review['maBaiViet']; ?>'><?php echo $review['tieuDe']; ?></option>
                    <?php endforeach; ?>
                </select>
            </div>
        </div>
        
        <br>
        <form action="editSong.php" method="post">
            <div class="field">
                <div class="label">
                    <label for="">Mã bài viết</label>
                </div>
                <div class="input">
                    <input type="text" name="maBaiViet" id="maBaiViet">
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Tiêu Đề</label>
                </div>
                <div class="input">
                    <input type="text" name="tieuDe">
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Tác giả</label>
                </div>
                <div class="input">
                    <select name="maTacGia">
                        <?php foreach ($reviewers as $reviewer): ?>
                            <option value='<?php echo $reviewer['maTacGia'] ?>'><?php echo $reviewer['tenTacGia']; ?></option>
                        <?php endforeach; ?>
                    </select>
                    <input type="text" name="">
                    <input type="submit" name="" value="Them TG">
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Ngày viết</label>
                </div>
                <div class="input">
                    <input type="date" name="ngayViet" value="">
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Bài Hát</label>
                </div>
                <div class="input">
                    <input type="text" name="tenBaiHat" value="">
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Thể Loại</label>
                </div>
                <div class="input">
                    <select name="maTheLoai">
                        <?php foreach ($genres as $genre): ?>
                            <option value='<?php echo $genre['maTheLoai'] ?>'><?php echo $genre['tenTheLoai']; ?></option>
                        <?php endforeach; ?>
                    </select>
                </div>
            </div>
            <div class="field">
                <div class="label">
                    <label for="">Tóm tắt</label>
                </div>
                <div class="input">
                    <textarea name="tomTat" rows="5" cols="40"></textarea>
                </div>
            </div>

            <div class="field">
                <div class="label"></div>
                <div class="submitBtn">
                    <input type="submit" name="submit" value="Cập nhật">
                    <input type="submit" value="Reset">
                </div>
                
            </div>
        </form>
    </div>
</body>
</html>