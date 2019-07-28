//
//  Domain.h
//  ProgramacaoCientifica
//
//  Created by Guilherme Albertini on 28/07/19.
//  Copyright © 2019 Guilherme Albertini. All rights reserved.
//

#ifndef Domain_h
#define Domain_h

void assign_matrix(int m1[3][3], int m2[3][3]){
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

#endif /* Domain_h */
