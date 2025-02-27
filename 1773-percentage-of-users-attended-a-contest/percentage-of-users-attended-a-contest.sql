# Write your MySQL query statement below

SELECT
    r.contest_id,
    ROUND((COUNT(r.contest_id)/(SELECT Count(*) from users))*100,2) as percentage
FROM
    users u
JOIN 
    register r
ON
    u.user_id = r.user_id
GROUP BY
    r.contest_id
ORDER BY
    percentage DESC,
    r.contest_id ASC
;