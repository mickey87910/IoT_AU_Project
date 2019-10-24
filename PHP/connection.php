<?php
$HostName = "localhost";
$DatabaseName = "";
$HostUser = "";
$HostPass = "";
$con=mysqli_connect($HostName, $HostUser, $HostPass, $DatabaseName);
if(!$con){
	die("Connection failed:".mysqli_connect_error());
}
?>
