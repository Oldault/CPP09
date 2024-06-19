/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:29 by oldault           #+#    #+#             */
/*   Updated: 2024/06/19 13:08:00 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
#define __UTILS_HPP__

#include "PMergeMe.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);

void printDemo();
void printVec(const std::vector<std::string>& vec);

#endif // __UTILS_HPP__