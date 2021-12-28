<body>

<?php
$mysqli = new mysqli("kdenisb.ru:23306", "stud20", "Zz8Gws4Vv", "stud20_TAZ");
if ($mysqli->connect_errno) 
{
	printf("Connection Error!: %s\n", $mysqli->connect_error);
 	exit();
}

if ($result = $mysqli->query("SELECT `3_student`.`code_of_report_card`, `3_student`.`surname`, `3_student`.`group_name`, `3_student`.`address`
FROM `3_student`
WHERE `3_student`.`code_of_report_card` =".$_GET[code_of_report_card].";")) // '5'
{
 	printf("Selected strings are %d .\n", $result->num_rows);
}
?>

<table border=1>
<?php
while( $row = $result->fetch_array(MYSQLI_ASSOC) )
{
	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>", $row["code_of_report_card"], $row["surname"], $row["group_name"], $row["address"]);
}
?>
</table>
<?php

$result->close();
$mysqli->close();
?>
