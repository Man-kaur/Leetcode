SELECT
    st.student_id,
    st.student_name,
    su.subject_name,
    COUNT(e.student_id) as attended_exams
FROM
    students st
CROSS JOIN
    subjects su
LEFT JOIN
    examinations e
    ON st.student_id = e.student_id
    AND su.subject_name = e.subject_name
GROUP BY
    st.student_id,
    st.student_name,
    su.subject_name
ORDER BY
    st.student_id ASC,
    su.subject_name ASC
;