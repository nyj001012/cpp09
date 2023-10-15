/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Database.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:10:42 by yena              #+#    #+#             */
/*   Updated: 2023/10/15 15:01:46 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//
// Created by 나예진 on 2023/10/15.
//

#ifndef EX00__DATABASE_HPP_
#define EX00__DATABASE_HPP_

#include <map>
#include <iostream>
#include <fstream>

class Database {
 public:
  Database();
  Database(const Database &copy);
  Database &operator=(const Database &copy);
  ~Database();
  static std::map<std::string, float> readDatabase();
};

#endif //EX00__DATABASE_HPP_
