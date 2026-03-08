var assert = require('assert');
var solution008 = require('../src/euler/solution008');

describe('Solution008', function() {
  describe('answer', function() {
    it('will answer problem 008', function() {
      assert.equal(solution008.answer(), 23514624000);
    });
  });
});