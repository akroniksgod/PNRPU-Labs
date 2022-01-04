SELECT COUNT(*) 
FROM `3_subject` 
INNER JOIN `3_exam` ON `3_exam`.`code_of_subject` = `3_subject`.`code_of_subject` 
WHERE `3_exam`.`mark` > 3
