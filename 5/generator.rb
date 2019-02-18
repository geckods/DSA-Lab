=begin
b) Generate the following different input distributions and repeat Exercise 2 for each
of them:
 Input list where several duplicate entries
 Input list where a single entry is replicated a large number of times
 Input list that is already in sorted order
 Input list that is sorted in reverse order

typedef struct {
	unsigned long long card_no;
	char bank_code[6];
	char expiry_date[8];
	char first_name[20];
	char last_name[20];
} CREDIT_CARD;

=end

#This is a ruby script used to generate the required inputs for DSA Lab 5

def randstring(len)
	str = ""
	len.times do
		a = rand(26)
		str+= ('a'.ord+a).chr
	end
	return str
end

def randdate()
	str = ""
	2.times{str+= rand(10).to_s}
	str+= "/"
	4.times{str+= rand(10).to_s}
	return str
end

def generateRand()
	return "\"" + [rand(10000000000000000),randstring(5),randdate(),randstring(5),randstring(5)].map(&:to_s).join(",") +"\""
end

def generateDuplicates(filename,length)
	root = length**0.5
	root = root.to_i
	File.open(filename,"w") do |f|
		i=0
		while i<length
			str = generateRand()
			root.times do
				f.write str
				f.write "\n"
			end
			i+=root
		end
	end
end

def generateSingle(filename,length)
	root = length**0.5
	root = root.to_i
	File.open(filename,"w") do |f|
		str = generateRand()
		length.times do
			f.write str
			f.write "\n"
		end
	end
end

def generateSorted(filename,length)
	arr = []
	length.times do
		arr.push generateRand()
	end
	arr.sort_by!{|x| x.split(",")[0][1..-1].to_i}
	File.open(filename,"w") do |f|
		arr.each do |x|
			f.write x
			f.write "\n"
		end
	end
end

def generateReverse(filename,length)
	arr = []
	length.times do
		arr.push generateRand()
	end
	arr.sort_by!{|x| -x.split(",")[0][1..-1].to_i}
	File.open(filename,"w") do |f|
		arr.each do |x|
			f.write x
			f.write "\n"
		end
	end
end

generateDuplicates("Duplicates",10000)
generateSingle("Single",10000)
generateSorted("Sorted",10000)
generateReverse("Reverse",10000)