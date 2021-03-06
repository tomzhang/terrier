#pragma once

#include <memory>
#include <vector>

#include "optimizer/rule.h"

namespace terrier::optimizer {

/**
 * Rule transforms Logical Scan -> Sequential Scan
 */
class LogicalGetToPhysicalSeqScan : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalGetToPhysicalSeqScan();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalExternalFileGet -> ExternalFileGet
 */
class LogicalExternalFileGetToPhysicalExternalFileGet : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalExternalFileGetToPhysicalExternalFileGet();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Generate dummy scan for queries like "SELECT 1", there's no actual
 * table to generate
 */
class LogicalGetToPhysicalTableFreeScan : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalGetToPhysicalTableFreeScan();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical Scan -> Index Scan
 */
class LogicalGetToPhysicalIndexScan : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalGetToPhysicalIndexScan();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule that transforms query derived scans for nested queries
 */
class LogicalQueryDerivedGetToPhysicalQueryDerivedScan : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalQueryDerivedGetToPhysicalQueryDerivedScan();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalDelete -> Delete
 */
class LogicalDeleteToPhysicalDelete : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDeleteToPhysicalDelete();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalUpdate -> Update
 */
class LogicalUpdateToPhysicalUpdate : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalUpdateToPhysicalUpdate();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalInsert -> Insert
 */
class LogicalInsertToPhysicalInsert : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalInsertToPhysicalInsert();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalInsertSelect -> InsertSelect
 */
class LogicalInsertSelectToPhysicalInsertSelect : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalInsertSelectToPhysicalInsertSelect();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalGroupBy -> HashGroupBy
 */
class LogicalGroupByToPhysicalHashGroupBy : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalGroupByToPhysicalHashGroupBy();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalAggregate -> Aggregate
 */
class LogicalAggregateToPhysicalAggregate : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalAggregateToPhysicalAggregate();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical Inner Join to InnerNLJoin
 */
class LogicalInnerJoinToPhysicalInnerNLJoin : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalInnerJoinToPhysicalInnerNLJoin();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical Inner Join to InnerHashJoin
 */
class LogicalInnerJoinToPhysicalInnerHashJoin : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalInnerJoinToPhysicalInnerHashJoin();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms LogicalLimit -> Limit
 */
class LogicalLimitToPhysicalLimit : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalLimitToPhysicalLimit();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical Export -> Physical Export
 */
class LogicalExportToPhysicalExport : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalExportToPhysicalExport();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateDatabase -> Physical CreateDatabase
 */
class LogicalCreateDatabaseToPhysicalCreateDatabase : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateDatabaseToPhysicalCreateDatabase();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateFunction -> Physical CreateFunction
 */
class LogicalCreateFunctionToPhysicalCreateFunction : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateFunctionToPhysicalCreateFunction();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateIndex -> Physical CreateIndex
 */
class LogicalCreateIndexToPhysicalCreateIndex : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateIndexToPhysicalCreateIndex();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateTable -> Physical CreateTable
 */
class LogicalCreateTableToPhysicalCreateTable : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateTableToPhysicalCreateTable();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateNamespace -> Physical CreateNamespace
 */
class LogicalCreateNamespaceToPhysicalCreateNamespace : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateNamespaceToPhysicalCreateNamespace();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateTrigger -> Physical CreateTrigger
 */
class LogicalCreateTriggerToPhysicalCreateTrigger : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateTriggerToPhysicalCreateTrigger();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical CreateView -> Physical CreateView
 */
class LogicalCreateViewToPhysicalCreateView : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalCreateViewToPhysicalCreateView();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropDatabase -> Physical DropDatabase
 */
class LogicalDropDatabaseToPhysicalDropDatabase : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropDatabaseToPhysicalDropDatabase();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropTable -> Physical DropTable
 */
class LogicalDropTableToPhysicalDropTable : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropTableToPhysicalDropTable();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropIndex -> Physical DropIndex
 */
class LogicalDropIndexToPhysicalDropIndex : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropIndexToPhysicalDropIndex();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropNamespace -> Physical DropNamespace
 */
class LogicalDropNamespaceToPhysicalDropNamespace : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropNamespaceToPhysicalDropNamespace();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropTrigger -> Physical DropTrigger
 */
class LogicalDropTriggerToPhysicalDropTrigger : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropTriggerToPhysicalDropTrigger();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

/**
 * Rule transforms Logical DropView -> Physical DropView
 */
class LogicalDropViewToPhysicalDropView : public Rule {
 public:
  /**
   * Constructor
   */
  LogicalDropViewToPhysicalDropView();

  /**
   * Checks whether the given rule can be applied
   * @param plan OperatorExpression to check
   * @param context Current OptimizationContext executing under
   * @returns Whether the input OperatorExpression passes the check
   */
  bool Check(common::ManagedPointer<OperatorExpression> plan, OptimizationContext *context) const override;

  /**
   * Transforms the input expression using the given rule
   * @param input Input OperatorExpression to transform
   * @param transformed Vector of transformed OperatorExpressions
   * @param context Current OptimizationContext executing under
   */
  void Transform(common::ManagedPointer<OperatorExpression> input,
                 std::vector<std::unique_ptr<OperatorExpression>> *transformed,
                 OptimizationContext *context) const override;
};

}  // namespace terrier::optimizer
