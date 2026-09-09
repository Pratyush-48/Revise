# Write your MySQL query statement below
with tem as(
    select r.book_id as book_id,
    sum(case when session_rating>=4 then 1 else 0 end) as four,
    sum(case when session_rating<=2 then 1 else 0 end) as two,
    max(session_rating) as high,
    min(session_rating) as low,
    avg(case when session_rating>=4 then 1 when session_rating<=2 then 1 else 0 end) as pol,
    b.title as title,
    b.author as author,
    b.genre as genre,
    b.pages as pages
    from reading_sessions r inner join books b on r.book_id = b.book_id
    group by r.book_id
),
tem2 as(
    select book_id,
    count(session_id) as coun
    from reading_sessions
    group by book_id
    having count(session_id) >= 5
)
select book_id,title,author,genre,pages,
(high-low) as rating_spread,
round(pol,2) as polarization_score
from tem
where four>0 and two>0 and book_id in(select book_id from tem2) and pol>=0.6
order by polarization_score desc,title desc;