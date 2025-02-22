# Write your MySQL query statement below
SELECT
    em.name, bo.bonus
FROM 
    Employee em
LEFT JOIN
    BONUS bo
ON
    em.empId = bo.empId
WHERe 
    bo.bonus < 1000
    OR bo.bonus IS NULL;