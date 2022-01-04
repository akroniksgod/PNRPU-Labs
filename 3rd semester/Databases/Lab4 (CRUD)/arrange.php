<!DOCTYPE html>
<html>
  <head>
    <title>Arrange an examination</title>
  </head>
  <body>
	<?php
		include 'connect.php';
		
		$result = $bdd->query("INSERT INTO `3_exam` 
(`3_exam`.`code_of_report_card`, `3_exam`.`code_of_subject`, `3_exam`.`date_of_exam`) 
VALUES (".$_GET[code_of_report_card].",".$_GET[code_of_subject].",'".$_GET[date_of_exam]."');");
	?>
		<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
  </body>
</html>