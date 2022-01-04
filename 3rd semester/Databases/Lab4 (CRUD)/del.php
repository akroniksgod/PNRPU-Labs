<!DOCTYPE html>
<html>
  <head>
    <title>Remove an examination</title>
  </head>
  <body>
	<?php
		include 'connect.php';

		$result = $bdd->query("DELETE FROM `3_exam` WHERE `3_exam`.`id_exam`=".$_GET[id_exam].";");
	?>
		<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
  </body>
</html>