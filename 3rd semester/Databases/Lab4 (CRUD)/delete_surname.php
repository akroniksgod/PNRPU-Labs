<!DOCTYPE html>
<html>
<head>
	<title>Deleting a surname</title>
</head>
<body>
	<?php 
		include 'connect.php';	
		$request = "DELETE FROM `3_student` WHERE `3_student`.`code_of_report_card` = ".$_GET[code_of_report_card]."";		
		$bdd->query($request);	
	?>
	<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
</body>
</html>	