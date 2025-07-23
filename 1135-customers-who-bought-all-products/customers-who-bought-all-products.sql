SELECT 
    a.customer_id
FROM 
    Customer a
GROUP BY 
    a.customer_id
HAVING 
    COUNT(DISTINCT a.product_key) = (SELECT COUNT(*) FROM Product);
