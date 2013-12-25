#!/usr/bin/ruby
require 'prime'
class Integer
	def totient() (-1)**self.prime_division.reduce(0){|s,e|s+=e[1]} end
end

f=[0]+(1..1000000).map(&:totient)
g=[0]
(1..1000000).map{|i|g[i]=g[i-1]+f[i]}
gets.to_i.times{
	n=gets.to_i
	puts g[n]<0 ? '-' : g[n]>0 ? '+' : 0
}