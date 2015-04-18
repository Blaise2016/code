function y = numInt(a, b) 
	mex myQuad.c;
	y = myQuad(a, b);
end