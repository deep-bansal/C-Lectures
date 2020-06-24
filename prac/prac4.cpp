if(isSafe(board,i,j,row,col))
   {
        soln[i][j]=1;
    if(ratinmaze(board,soln,i,j+1,row,col))
    {
        return true;
    }
    if(ratinmaze(board,soln,i+1,j,row,col))
    {
        return true;
    }
	 if(ratinmaze(board,soln,i-1,j,row,col))
    {
        return true;
    }
	if(ratinmaze(board,soln,i,j-1,row,col))
    {
        return true;
    }
   }