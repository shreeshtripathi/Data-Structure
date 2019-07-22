or(int j = 0; j < e.size(); j++){
            BEdge be = e.get(j);
            if(res[be.v1] != Integer.MAX_VALUE && res[be.v1] + be.wt < res[be.v2]){
                System.out.println("Negative Cycle detect");
                return;
            }
        }