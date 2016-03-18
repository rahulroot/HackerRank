def cal_fab
	nums = gets.scan(/\d+/).map(&:to_i)
	$a = nums[0]
	$b = nums[1]
	$n = nums[2]
	$i = 3
	while $i <= $n do
		$tmp = $b * $b
		$final = $tmp + $a
		$a = $b
		$b = $final
		$i +=1;
	end

	print "#{$final}\n"

end

cal_fab
