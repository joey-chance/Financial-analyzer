#include "../../Header/Metric/SGA_SY.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

SGA_SY::SGA_SY(const Stock& stock, int& score, std::unordered_map<CategoryType, int>* CategoryScores, std::unordered_map<MetricType, int>* MetricScores,
	std::unordered_map<CategoryType, int>* MaxCategoryScores, std::unordered_map<MetricType, int>* MaxMetricScores, std::unordered_map<MetricType, long double>* MetricPerformances)
	: MetricSY(stock, score, CategoryScores, MetricScores, MaxCategoryScores, MaxMetricScores, MetricPerformances)
{
	long double sellingGeneralAndAdministrativeExpenses = stock.get_IS_metric(IncomeStatementMetrics::sellingGeneralAndAdministrativeExpenses, 0);
	long double grossProfit = stock.get_IS_metric(IncomeStatementMetrics::grossProfit, 0);
	this->set_performance(sellingGeneralAndAdministrativeExpenses / grossProfit); // set actual performance of this metric (i.e. actual gross profit margin)
	this->scoreMetric();
	this->updateMetricPerformances();
}

bool SGA_SY::highScore()
{
	return (this->performance >= 0 && this->performance <= 0.3);
}

bool SGA_SY::medScore()
{
	return (this->performance >= 0 && this->performance <= 0.4);
}

bool SGA_SY::lowScore()
{
	return (this->performance >= 0 && this->performance <= 0.5);
}