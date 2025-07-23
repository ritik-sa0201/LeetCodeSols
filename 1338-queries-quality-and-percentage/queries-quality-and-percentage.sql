SELECT 
    a.query_name,
    ROUND(SUM(a.rating / a.position) / COUNT(*), 2) AS quality,
    ROUND(SUM(CASE WHEN a.rating < 3 THEN 1 ELSE 0 END) * 100.0 / COUNT(*), 2) AS poor_query_percentage
FROM 
    Queries a
GROUP BY 
    a.query_name;
