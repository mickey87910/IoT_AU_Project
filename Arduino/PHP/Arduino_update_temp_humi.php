<?php
    include 'connection.php';
    $temp = $_REQUEST['temp'];
    $humi = $_REQUEST['humi'];
    $result=mysqli_query($con,"UPDATE temp_humi_num SET `temp`=$temp , `humi`=$humi WHERE 1");
?>