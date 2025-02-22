# Write your MySQL query statement below
SELECT
    st.student_id,
    st.student_name,
    sub.subject_name,
    COUNT(exam.subject_name) as attended_exams
FROM
    Students st
CROSS JOIN
    Subjects sub
LEFT JOIN
    Examinations exam
ON  st.student_id = exam.student_id
    AND sub.subject_name = exam.subject_name
GROUP BY
    st.student_name,
    sub.subject_name
ORDER BY
    st.student_id ASC, sub.subject_name ASC
    ;