<body>

<?php
$bdd=new PDO('mysql:host=kdenisb.ru;port=23306;dbname=stud20_TAZ',
"stud20", "Zz8Gws4Vv");
?>

<table border=1>
<?php

foreach($bdd->query("SELECT `3_student`.`surname`, `3_subject`.`name`, `3_exam`.`mark` FROM `3_student`
INNER JOIN `3_exam` ON `3_exam`.`code_of_report_card` = `3_student`.`code_of_report_card`
INNER JOIN  `3_subject` ON `3_subject`.`code_of_subject` = `3_exam`.`code_of_subject`
WHERE `3_exam`.`mark` >= 4 AND `3_exam`.`date_of_exam` >'".$_GET[date_of_exam]."';") as $row) 
{
	printf("<tr><td>%s</td><td>%s</td><td>%s</td></tr>", $row["surname"], $row["name"], $row["mark"]);

}
?>

</table>
<?php
?>
