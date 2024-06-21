/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:29 by oldault           #+#    #+#             */
/*   Updated: 2024/06/21 10:00:17 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "PMergeMe.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);

void printDemo();
void printVec(const std::vector<int>& vec);
bool is_number(const std::string& s);

#endif // __UTILS_HPP__