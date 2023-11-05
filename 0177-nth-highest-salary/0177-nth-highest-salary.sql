# sort in desc order then offset limit by N
# outer select is to return NULL

CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
SET N = N - 1;
  RETURN (
    SELECT (SELECT DISTINCT emp.salary
    FROM Employee as emp
    ORDER BY salary DESC LIMIT N, 1)
  );
END