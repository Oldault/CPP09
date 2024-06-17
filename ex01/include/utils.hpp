/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oldault <oldault@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 20:56:29 by oldault           #+#    #+#             */
/*   Updated: 2024/06/17 21:22:23 by oldault          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_H__
#define __UTILS_H__

#include "RPN.hpp"

template <typename Out>
void split(const std::string &s, char delim, Out result);
std::vector<std::string> split(const std::string &s, char delim);
void printDemo();

#endif // __UTILS_H__