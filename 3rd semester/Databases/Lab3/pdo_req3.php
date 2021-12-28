<body>

<?php
$bdd=new PDO('mysql:host=kdenisb.ru;port=23306;dbname=stud20_TAZ',
"stud20", "Zz8Gws4Vv");
?>

<table border=1>
<?php

foreach($bdd->query("SELECT `3_student`.`code_of_report_card`, `3_student`.`surname`, `3_student`.`group_name`, `3_student`.`address`
FROM `3_student`
WHERE `3_student`.`code_of_report_card` =".$_GET[code_of_report_card].";") as $row) 
{
	printf("<tr><td>%s</td><td>%s</td><td>%s</td><td>%s</td></tr>", $row["code_of_report_card"], $row["surname"], $row["group_name"], $row["address"]);
}
?>

</table>
<?php
?>
