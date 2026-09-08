# Write your MySQL query statement below
with tem as(
    select user_id,count(content_id) as tot
    from reactions
    group by user_id
),
tem2 as(
    select user_id,count(reaction) as ind,reaction from reactions
    group by user_id,reaction
)
select tem2.user_id,tem2.reaction as dominant_reaction,round(ind/tot,2) as reaction_ratio from
tem inner join tem2 on tem.user_id = tem2.user_id
where tem.tot>=5 and (ind/tot)>=0.6
order by reaction_ratio desc,user_id asc;