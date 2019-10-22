<?php
    include 'connection.php';
    $num = $_REQUEST['num'];
    echo "$num";
    $result=mysqli_query($con,"UPDATE person_num SET `num`=$num WHERE 1");
    $number_of_rows = mysqli_num_rows($result);
    if($result){
        echo 'suceessed';
    }else{
        echo 'failed';
    }
?>
