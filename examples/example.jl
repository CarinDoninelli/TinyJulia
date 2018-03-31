a::Array{Int} = [7,4,9,2,10,1,5,3,8,6,false]


for i = 1:11
    for j = 1:11-1
        if a[j] > a[j+1]
            temp::Int = a[j+1]
            a[j+1] = a[j]
            a[j]=temp
        end
    end
end

for i = 1:11
    println(a[i])
end
