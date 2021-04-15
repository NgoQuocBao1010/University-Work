<?php 
    // Database connection 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    $deleteID = '____';
    $deleteMsg = '';    
    if (isset($_GET['delete'])) {
        $deleteID =  $_GET['delete'];
        $deleteQuery = "DELETE FROM Reviews WHERE maBaiViet=$deleteID";
        $deleteMsg = "Bài Viết Có Mã là $deleteID vừa bị xóa"; 

        if (mysqli_query($conn, $deleteQuery)) {
            // header('Location: deleteSong.php');
        }
        else  {
            echo "Error: " . mysqli_error($conn);
        }
    }

    $filterTexts = '';
    if (isset($_GET['filter'])) {
        $filterTexts = $_GET['filterText'];
    }

    if (isset($_GET['clear'])) {
        $filterTexts = '';
    }


    // Get reviews from database
    $getReviews = "SELECT maBaiViet, tieuDe, tenBaiHat, tomTat, ngayViet, tenTacGia, tenTheLoai
            FROM Reviews 
            LEFT JOIN Reviewers on Reviews.maTacGia = Reviewers.maTacGia
            LEFT JOIN Genres on Reviews.maTheLoai = Genres.maTheLoai
            WHERE tenBaiHat LIKE '%$filterTexts%' OR tenTacGia LIKE '%$filterTexts%'
                OR tomTat LIKE '%$filterTexts%' OR tieuDe LIKE '%$filterTexts%' 
                OR tenTheLoai LIKE '%$filterTexts%' OR ngayViet LIKE '%$filterTexts%'";
    
    $result = mysqli_query($conn, $getReviews);
    $reviews = mysqli_fetch_all($result, MYSQLI_ASSOC);
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="style.css">
    <title>Xoa Bai Hat</title>
</head>
<body>
    <a href="addSong.php">Add Song</a>
    <a href="editSong.php">Edit Song</a>
    <div class="container">
        <h1>Xoa Bai Viet</h1>
        <hr>
        <form class="filter" action="deleteSong.php" method="GET">
            <input type="text" name="filterText" value="<?php echo $filterTexts; ?>">
            <input type="submit" name="filter" value="Lọc bài viết">
            <input type="submit" name="clear" value="Bỏ lọc">
        </form>


        <h2>Số bài viết: <?php echo count($reviews); ?></h2>
        <h3><?php echo $deleteMsg; ?></h3>

        <?php foreach ($reviews as $review): ?>
            <form action="" method="GET" class="reviewPost" onsubmit="return confirmDelete('<?php echo $review['tieuDe'];?>')">
                <div class="details">
                    <p class="name">Mã bài viết</p> <p class="value"><?php echo $review['maBaiViet']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Tiêu Đề</p><p class="value"><?php echo $review['tieuDe']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Tác Giả</p> <p class="value"><?php echo $review['tenTacGia']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Ngày Viết</p> <p class="value"><?php echo $review['ngayViet']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Bài Hát</p> <p class="value"><?php echo $review['tenBaiHat']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Thể Loại</p> <p class="value"><?php echo $review['tenTheLoai']; ?></p>
                </div>
                <div class="details">
                    <p class="name">Tóm tắt</p> <p class="value"><?php echo $review['tomTat']; ?></p>
                </div>
                <div class="details">
                    <div class="name"></div>
                    <input class="value" type="submit" name="delete" value="Xóa bài viết" style="width: 15%; margin-left: 20px; font-size: 15px;">
                    <input type="hidden" name="delete" value="<?php echo $review['maBaiViet'] ?>">
                </div>
                <hr>
            </form>
        <?php endforeach; ?>
    </div>
</body>
<script>
    function confirmDelete(name) {
        console.log('WTf');
        if (confirm("Delete reviews '" + name + "'?")) {
            return true;
        }
        else {
            return false;
        }
    }
</script>
</html>