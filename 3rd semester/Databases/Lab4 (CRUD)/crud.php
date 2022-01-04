<?php include 'connect.php'; ?>
<?php include 'request.php'; ?>
<!DOCTYPE html>
<html>
  <head>
    <title></title>
     <style type="text/css">
       .visit {border: solid black 1px;}
     </style>
  </head>
  <body>

Choose the exact date<br></br>
<div>
<form action = "index.php", method = get>
	<select name="date_of_exam">
		<option></option>
<?php
$result = $bdd->query($req3);
foreach($result as $row)
{
?>

	<option value="<?=$row["date_of_exam"]?>"><?=$row["date_of_exam"]?></option>
<?php
}
?>
	</select>
	<button>Show this date</button>
</form>
</div>
  </body>
</html>