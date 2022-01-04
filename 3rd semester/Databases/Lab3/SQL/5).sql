SELECT `3_student`.`surname`, `3_student`.`group_name`, `3_student`.`address`, `3_student`.`code_of_report_card`, `3_subject`.`name`, `3_exam`.`mark`
FROM `3_student`
	, `3_subject` 
	LEFT JOIN `3_exam` ON `3_subject`.`code_of_subject` = `3_exam`.`code_of_subject`
WHERE `3_exam`.`mark` = 'C';