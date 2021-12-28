<body>

<?php
$mysqli = new mysqli("kdenisb.ru:23306", "stud20", "Zz8Gws4Vv", "stud20_TAZ");
if ($mysqli->connect_errno) 
{
	printf("Connection Error!: %s\n", $mysqli->connect_error);
 	exit();
}

if ($result = $mysqli->query("SELECT `3_student`.`surname`, `3_subject`.`name`, `3_exam`.`mark` FROM `3_student`
INNER JOIN `3_exam` ON `3_exam`.`code_of_report_card` = `3_student`.`code_of_report_card`
INNER JOIN  `3_subject` ON `3_subject`.`code_of_subject` = `3_exam`.`code_of_subject`
WHERE `3_exam`.`mark` >= 4 AND `3_exam`.`date_of_exam` >'".$_GET[date_of_exam]."';")) //'2021-07-12'
{
 	printf("Selected strings are %d .\n", $result->num_rows);
}
?>

<table border=1>
<?php
while( $row = $result->fetch_array(MYSQLI_ASSOC) )
{
	printf("<tr><td>%s</td><td>%s</td><td>%s</td></tr>", $row["surname"], $row["name"], $row["mark"]);
}
?>
</table>
<?php

$result->close();
$mysqli->close();
?>
