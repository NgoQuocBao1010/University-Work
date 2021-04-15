<?php
    $q = intval($_GET['q']);

    // Database connection 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    // Get reviews from database
    $getReviews = "SELECT maBaiViet, tieuDe, tenBaiHat, tomTat, ngayViet, Reviews.maTacGia, Reviews.maTheLoai
            FROM Reviews 
            LEFT JOIN Reviewers on Reviews.maTacGia = Reviewers.maTacGia
            LEFT JOIN Genres on Reviews.maTheLoai = Genres.maTheLoai
            WHERE maBaiViet=$q";
    
    $result = mysqli_query($conn, $getReviews);
    $reviews = mysqli_fetch_all($result, MYSQLI_ASSOC);
    // print_r($reviews);
    echo json_encode($reviews);
?>