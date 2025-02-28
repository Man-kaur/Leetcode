-- DATE_FORMAT(D.DA, "%Y-%m")

SELECT
    DATE_FORMAT(t.trans_date, "%Y-%m") as month,
    country, 
    COUNT(trans_date) as trans_count,
    SUM(state = 'approved') as approved_count,
    SUM(amount) as trans_total_amount,
    SUM(CASE WHEN state = "approved" THEN amount ELSE 0 END) as approved_total_amount
FROM 
    Transactions t
GROUP BY 
    month, country;