<?php
    $dbusername = "Injection";  $dbpassword = "InjectionAdmin";  
    $server = "localhost"; 
    $dbconnect = mysql_pconnect($server, $dbusername, $dbpassword);
    $dbselect = mysql_select_db("test",$dbconnect);
    $sql = "INSERT INTO injection1 (time1, amount1) VALUES('$time1','$amount1')";
    $sql = "INSERT INTO injection2 (time2, amount2) VALUES('$time2','$amount2')";
    mysql_query($sql);
?>
