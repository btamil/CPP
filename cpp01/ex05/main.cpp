/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tponnusa <tponnusa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:24:45 by tponnusa          #+#    #+#             */
/*   Updated: 2024/03/20 14:52:37 by tponnusa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl service;

    service.complain("debug");
    service.complain("info");
    service.complain("warning");
    service.complain("error");
    service.complain("nothing");
    service.complain("");
    return (0);
}