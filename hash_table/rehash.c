//
// Created by joan on 19-7-9.
//

#include "rehash.h"


/**
 * 再散列：
 *
 *      采用开放定址法的hash Table，装填因子应该小于0.5；(减小探测次数)
 *      当大于0.5时，采用再次hash的方式，使装填因子下降。
 *
 *  装填因子　＝　元素数量　/　hash表长度。
 *
 */