var assert = require('assert');
var solution022 = require('../src/euler/solution022');

describe('Solution022', function() {
  describe('answer', function() {
    it('will answer problem 022', function() {
      assert.equal(solution022.answer(), 871198282);
    });
  });
});