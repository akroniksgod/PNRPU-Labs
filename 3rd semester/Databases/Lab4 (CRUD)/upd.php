<!DOCTYPE html>
<html>
  <head>
    <title>Update an examination</title>
  </head>
  <body>
<?php
include 'connect.php';
include 'request.php';
?>
	<form action = "update.php" method = "get">
		<input type="hidden" name = "id_exam" value = "<?=$_GET[id_exam]?>">
		<?php echo $_GET["surname"];?>
		<select name = "code_of_subject">
			<option>Choose subject</option>
<?php
$result2 = $bdd->query($req4);
foreach($result2 as $row2) 
{
?>
			<option value="<?=$row2["code_of_subject"]?>"><?=$row2["name"]?></option>
<?php
}
?>	
		</select>
		<select name = "date_of_exam">
			<option>Choose Date</option>
<?php
$result3 = $bdd->query($req3);
foreach($result3 as $row3) 
{
?>			
			<option value="<?=$row3["date_of_exam"]?>"><?=$row3["date_of_exam"]?></option>
<?php
}
?>
		</select>
			<button>Update</button>
		<!--<a href="update.php?id_exam=<?=$_GET[id_exam]?>&code_of_subject=<?=$row2["code_of_subject"]?>&date_of_exam=<?=$row3["date_of_exam"]?>">Update</a>>
	</form>
		<a href="./?date_of_exam=<?=$_GET[date_of_exam]?>">Return</a>
  </body>
</html>