#fatw = 1
#fatu = 1
#auxw = num
#auxu = num

#while auxw > 0
#  fatw *= auxw
#  auxw -= 1
#end
#p fatw
#
#until auxu == 0
#  fatu *= auxu
#  auxu -= 1
#  end
#p fatu

def factorial(num)
  fat = 1
  until num == 0
    fat *= num
    num -= 1
  end
  fat
end

unless ARGV[0]
  p "Write a number"
  num = gets.chomp.to_i
else
  num = ARGV[0].to_i
end
puts "The factorial of #{num} is #{factorial(num)}."
