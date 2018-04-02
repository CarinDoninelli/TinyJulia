a::Array{Int} = [4,7,9,2,1,10,5,3,8,6,false]

function quickSort(left::Int, right::Int)::Int
    i::Int = left
    j::Int = right
    tmp::Int =0
    pivot::Int = a[(left + right) / 2]
    while (i <= j)
        while (a[i] < pivot)
            i = i+1
        end

        while (a[j] > pivot)
            j = j-1
        end
        if (i <= j)
            println("y")
            tmp = a[i]
            tmp2::Int = a[j]
            a[i] = tmp2
            a[j] = tmp
            i = i+1
            j = j-1
        end
    end

    if (left < j)
        quickSort(left, j)
    end
    if (i < right)
        quickSort(i, right)
    end
    return 0
end

quickSort(1, 11)

for x = 1:11
    println(a[x])
end