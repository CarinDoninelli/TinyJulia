arr::Array{Int} = [2,3,4,5,6]
arr[3] = 30
for i = 1:5
    println(i, "=", arr[i])
end