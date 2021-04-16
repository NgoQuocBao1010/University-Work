<?php
    // $q = intval($_GET['q']);
    $q = $_REQUEST["q"];

    // Database connection 
    $conn = mysqli_connect('localhost', 'root', '', 'school');
    mysqli_set_charset($conn, "utf8");
    if (!$conn) {
        echo mysqli_connect_error();
    }

    $returnValue = array('error' => '', 'newID' => '');

    // Generate new ID for reviewer
    $getLastId = "SELECT MAX(maTacGia) as maGanNhat FROM Reviewers";
    $result = mysqli_query($conn, $getLastId);
    $lastID = mysqli_fetch_array($result, MYSQLI_ASSOC)['maGanNhat'];
    $newID = $lastID + 1;
    $returnValue['newID'] = $newID;

    // Add new reviewer to database
    $addReviewerQuery = "INSERT INTO Reviewers(tenTacGia) VALUES ('$q')";

    if (!mysqli_query($conn, $addReviewerQuery)) {
        $returnValue['error'] =  "Error: " . "<br>" . mysqli_error($conn);
    } 
    
    echo json_encode($returnValue);
?>