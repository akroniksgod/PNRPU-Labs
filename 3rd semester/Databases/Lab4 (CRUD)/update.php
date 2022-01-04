<!DOCTYPE html>
<html>
  <head>
    <title>Updating</title>
  </head>
  <body>
	<?php
		include 'connect.php';

		$result = $bdd->query("UPDATE `3_exam` SET `code_of_subject`='".$_GET[code_of_subject]."',
												`date_of_exam` = '".$_GET[date_of_exam]."' WHERE `id_exam`=".$_GET[id_exam].";");
	?>
		<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
  </body>
</html>