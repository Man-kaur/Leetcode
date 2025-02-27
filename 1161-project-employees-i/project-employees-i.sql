# Write your MySQL query statement below
SELECT
    p.project_id,
    ROUND(SUM(em.experience_years)/COUNT(p.project_id), 2) as average_years
FROM
    project p
JOIN
    employee em
ON
    p.employee_id = em.employee_id
GROUP BY
    p.project_id;