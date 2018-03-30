
c::Array{Int} = [1,2,3,4,5]

for i = 1:5
    println("i = ", i)
    for j = 5:10
        println(j, " ", c[j/2])
    end
end
