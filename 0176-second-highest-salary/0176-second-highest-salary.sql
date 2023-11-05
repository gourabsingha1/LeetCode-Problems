# sort in desc order then offset limit by 1
# outer select is to return NULL

SELECT (SELECT DISTINCT emp.salary as SecondHighestSalary
FROM Employee as emp
ORDER BY salary DESC LIMIT 1, 1) as SecondHighestSalary;