<?php
    include 'connection.php';
    $temp = $_REQUEST['temp'];
    $humi = $_REQUEST['humi'];
    $time = date("Y-m-d h:i:sa");
    $result = mysqli_query($con,"UPDATE temp_humi_current SET `temperature`='$temp',`humidity`='$humi',`time`='$time' WHERE `id`=1");
    $result = mysqli_query($con,"INSERT INTO temp_humi_history (`temperature`,`humidity`,`time`) VALUES ('$temp','$humi','$time')");
?>
